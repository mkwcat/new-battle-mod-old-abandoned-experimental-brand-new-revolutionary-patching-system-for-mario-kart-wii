SECTIONS {
	.text : {
		*(.text*)
		*(.extern_repl*)
		KEEP(*(.replaced*))
	}
	.rodata : {
		*(.rodata*)
	}
	.data : {
        . = ALIGN(4);
        _replarray = .;
        KEEP(*(.replarray))
        _replarray_end = .;

        . = ALIGN(4);
        _externarray = .;
        KEEP(*(.externarray))
        _externarray_end = .;

        . = ALIGN(4);
		*(.data)
		*(.sdata)
		*(.sdata2)
	}
	.bss : {
		*(.bss*)
		*(.sbss*)
	}

	.ctors : {
        . = ALIGN(4);
		_ctors = .;
		*(.ctors)
		*(.init_array)
		_ctors_end = .;
	}
}
