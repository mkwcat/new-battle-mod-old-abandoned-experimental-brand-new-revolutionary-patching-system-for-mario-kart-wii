SECTIONS {
    . = 0x80004100;
    .text : {
        KEEP(*(.start))
        *(.text*)
        *(.rodata*)
        *(.data*)
    }
}
