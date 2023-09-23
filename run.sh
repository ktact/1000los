#!/bin/bash
set -xue

# Filepath of QEMU
QEMU=qemu-system-riscv32

# Start QEMU
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot
