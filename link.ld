SECTIONS {
	.text : {
		*(.text*)
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
