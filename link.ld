SECTIONS {
	.text : {
		*(.text*)
		*(.extern_repl*)
		KEEP(*(.replaced*))
	}

	.data : {
        . = ALIGN(4);
        _replarray = .;
        KEEP(*(.replarray))
        _replarray_end = .;

        . = ALIGN(4);
        _replrelarray = .;
        KEEP(*(.replrelarray))
        _replrelarray_end = .;

        . = ALIGN(4);
        _externarray = .;
        KEEP(*(.externarray))
        _externarray_end = .;

        *(.rodata*)

        . = ALIGN(4);
		*(.data*)
		*(.sdata*)
		*(.sdata2*)

		. = ALIGN(4);
		_ctors = .;
		*(.ctors)
		*(.init_array)
		_ctors_end = .;
	}

	.bss : {
		*(.bss*)
		*(.sbss*)
	}


}
