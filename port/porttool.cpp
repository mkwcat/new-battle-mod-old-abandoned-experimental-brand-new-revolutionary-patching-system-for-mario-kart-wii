#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u32 bswap32(u32 v)
{
    return (v << 24) | ((v << 8) & 0xFF0000) | ((v >> 8) & 0xFF00) | (v >> 24);
}

struct PortAddress {
    u32 addr_usa;
    u32 addr_jap;
    u32 addr_pal;
    u32 addr_kor;
};

struct ImpEntry {
    u32 moduleNum;
    u32 relOffset;
};

struct RelEntry {
    u16 offset;
    u8 type;
    u8 section;
    u32 addend;
};

static_assert(sizeof(RelEntry) == 0x8);

std::vector<PortAddress> g_addrs;

template <class T>
T RipFile(const char* path, u32* size)
{
    FILE* f = fopen(path, "rb");
    assert(f);
    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    fseek(f, 0, SEEK_SET);
    void* data = malloc(*size);
    assert(data);
    fread(data, 1, *size, f);
    fclose(f);
    return reinterpret_cast<T>(data);
}

void PushAddress(u32 address)
{
    if (
      std::find_if(
        g_addrs.begin(), g_addrs.end(),
        [&](const PortAddress& port) {
        return port.addr_pal == address;
        }
      ) != g_addrs.end())
        return;

    g_addrs.push_back({0, 0, address, 0});
}

void ParseOutputTxt()
{
    FILE* f = fopen("output.txt", "rb");
    if (!f) {
        printf("output.txt does not exist; skipping\n");
        return;
    }

    fclose(f);

    u32 size;
    auto fileData = RipFile<char*>("output.txt", &size);
    auto outputTxt = std::string(fileData, fileData + size);

    // scan every line
    u32 pos = 0;
    while (true) {
        PortAddress port;
        int ret = sscanf(
          outputTxt.c_str() + pos, "  { 0x%x, 0x%x, 0x%x, 0x%x },\r\n",
          &port.addr_usa, &port.addr_jap, &port.addr_pal, &port.addr_kor
        );

        g_addrs.push_back(port);

        if (ret != 4)
            break;

#if 0
        printf(
          "%08x %08x %08x %08x\n", port.addr_usa, port.addr_jap, port.addr_pal,
          port.addr_kor
        );
#endif

        auto found = outputTxt.find('\n', pos);
        if (found == std::string::npos)
            break;

        pos = found + 1;
    }
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("usage: porttool <pull|push>\n");
        return 1;
    }

    ParseOutputTxt();

    enum Cmd {
        CMD_PULL,
        CMD_PUSH,
        CMD_UNKNOWN,
    };

    std::string cmdStr = std::string(argv[1]);
    Cmd cmd = cmdStr == "pull"   ? CMD_PULL
              : cmdStr == "push" ? CMD_PUSH
                                 : CMD_UNKNOWN;

    assert(cmd != CMD_UNKNOWN);

    u32 inRelSize;
    u32* inRel = RipFile<u32*>("BattleP.rel", &inRelSize);
    u32* relE = RipFile<u32*>("BattleP.rel", &inRelSize);
    u32* relJ = RipFile<u32*>("BattleP.rel", &inRelSize);
    u32* relK = RipFile<u32*>("BattleP.rel", &inRelSize);
    assert(inRelSize >= 0x30);
    u32 relNum = bswap32(inRel[0x0 / 4]);

    u32 impTabOffset = bswap32(inRel[0x28 / 4]);
    u32 impSize = bswap32(inRel[0x2C / 4]);
    printf("impTabOffset: %08X\n", impTabOffset);

    for (u32 i = 0; i < impSize; i += sizeof(ImpEntry)) {
        ImpEntry* entry = (ImpEntry*) (((u8*) inRel) + impTabOffset + i);

        u32 moduleNum = bswap32(entry->moduleNum);
        if (moduleNum != 0)
            continue;

        u32 relOffset = bswap32(entry->relOffset);
        printf("relOffset: %08X\n", relOffset);

        RelEntry* rel = (RelEntry*) (((u8*) inRel) + relOffset);
        RelEntry* relEntE = (RelEntry*) (((u8*) relE) + relOffset);
        RelEntry* relEntJ = (RelEntry*) (((u8*) relJ) + relOffset);
        RelEntry* relEntK = (RelEntry*) (((u8*) relK) + relOffset);
        while (rel->type != 203) {
            // printf("type: %02X\n", rel->type);
            if (rel->type < 200 && rel->type != 0) {

                // printf("rel: 0x%08x\n", bswap32(rel->addend));
                if (cmd == CMD_PULL) {
                    PushAddress(bswap32(rel->addend));
                } else {
                    // port it!
                    auto port = std::find_if(
                      g_addrs.begin(), g_addrs.end(),
                      [&](const PortAddress& port) {
                        return port.addr_pal == bswap32(rel->addend);
                      });

                    if (port->addr_usa == 0 || port->addr_jap == 0 || port->addr_kor == 0) {
                        printf(
                          "WARNING: Missing ports for address 0x%08X!!!\n",
                          bswap32(rel->addend)
                        );
                    }

                    relEntE->addend = bswap32(port->addr_usa);
                    relEntJ->addend = bswap32(port->addr_jap);
                    relEntK->addend = bswap32(port->addr_kor);
                }
            }

            rel = rel + 1;
            relEntE++;
            relEntJ++;
            relEntK++;
        }
    }

    // printf("size: %08X", g_addrs.size());

    if (cmd == CMD_PULL) {
        std::sort(
          g_addrs.begin(), g_addrs.end(),
          [](const PortAddress& lhs, const PortAddress& rhs) -> bool {
              return lhs.addr_pal < rhs.addr_pal;
          }
        );

        FILE* f = fopen("input.txt", "w");

        for (auto port : g_addrs) {
            fprintf(
              f, "  { 0x%08X, 0x%08X, 0x%08X, 0x%08X },\n", port.addr_usa,
              port.addr_jap, port.addr_pal, port.addr_kor
            );
        }

        fclose(f);
    } else {
        FILE* f = fopen("BattleE.rel", "wb");
        fwrite(relE, 1, inRelSize, f);
        fclose(f);
        f = fopen("BattleJ.rel", "wb");
        fwrite(relJ, 1, inRelSize, f);
        fclose(f);
        f = fopen("BattleK.rel", "wb");
        fwrite(relK, 1, inRelSize, f);
        fclose(f);
    }
}
