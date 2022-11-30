#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void DCFlushRange(void* data, u32 length);
void ICInvalidateRange(void* data, u32 length);

#ifdef __cplusplus
}
#endif
