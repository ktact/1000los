ENTRY(boot)

/*
 * *(.text .text.*); のような記述は全ファイル('*')の.textと.text.で始まる名前のセクションをここに配置する
 *
 */
SECTIONS {
  . = 0x80200000;
  __kernel_base = .;

  .text :{
    KEEP(*(.text.boot));
    *(.text .text.*);
  }

  .rodata : ALIGN(4) {
    *(.rodata .rodata.*);
  }

  .data : ALIGN(4) {
    *(.data .data.*);
  }

  .bss : ALIGN(4) {
    __bss = .;     /* __bssはC言語から参照できる */
    *(.bss .bss.* .sbss .sbss.*);
    __bss_end = .; /* __bss_endもC言語から参照できる */
  }

  . = ALIGN(4);
  . += 128 * 1024; /* 128KB */
  __stack_top = .;

  . = ALIGN(4096);
  __free_ram = .;
  . += 64 * 1024 * 1024; /* 64MB */
  __free_ram_end = .;
}
