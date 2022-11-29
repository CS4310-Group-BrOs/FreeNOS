# CS 4310 - FreeNOS
- Andrew Arteaga
- Sergey Hambardzumyan
- Zane Reis
## Memory Management
### Layout in Physical Memory
FreeNOS’s memory layout is defined in lib/libarch/MemoryMap.cpp. It defines eight memory regions. The regions are defined as follows:
`typedef enum Region
    {
        KernelData,    /**<< Kernel program data from libexec, e.g. code, bss, (ro)data */
        KernelPrivate, /**<< Kernel dynamic memory mappings */
        UserData,      /**<< User program data from libexec, e.g. code, bss, (ro)data */
        UserHeap,      /**<< User heap */
        UserStack,     /**<< User stack */
        UserPrivate,   /**<< User private dynamic memory mappings */
        UserShare,     /**<< User shared dynamic memory mappings */
        UserArgs       /**<< Used for copying program arguments and file descriptors */
    }
Region;`
Virtual Memory Management is defined in /lib/libarch/intel/IntelPaging.cpp, and /lib/libarch/arm/ARMPaging.cpp for Intel and ARM processors respectively.

### Address Translation
FreeNOS uses two page tables (p1 and p2) for address translation. For ARM p1 is named ARMFirstTable and p2 is named ARMSecondTable. For Intel, p1 is named IntelPageDirectory and p2 is named IntelPageTable.

/lib/libarch/arm/ARMFirstTable.h:170
`u32 m_pages[4096];`
ARM’s first-level page table contains 4096 entries

/lib/libarch/arm/ARMSecondTable.h:99
`u32 m_pages[256];`
ARM’s second-level page table contains 256 entries

/lib/libarch/intel/IntelPageDirectory.h:168
`u32 m_tables[1024];`
Intel’s first-level page table contains 1024 entries

/lib/libarch/intel/IntelPageTable.h:99
`u32 m_pages[1024];`
Intel second-level page table also contains 1024 entries

The processor’s in-built TLB is used for both ARM and Intel processors. Any changes to the page table necessitate interacting with the processor’s TLB to flush or invalidate entries.
/lib/libarch/arm/ARMPaging.cpp:244
`tlb_invalidate(virt);`
/lib/libarch/intel/IntelPaging.cpp:109
`tlb_flush(virt);`

### Memory Allocator
/lib/liballoc/BitAllocator.h:52
`BitAllocator(const Range range, const Size chunkSize, u8 *bitmap = ZERO);`
\
FreeNOS allocates memory in an array of bits, in a specified range. A chunk size is passed as an argument that determines the size of each memory chunk. The bit array holds a 1 if the chunk is allocated and a 0 if the chunk is unallocated. A chunk can be allocated at the address that is next in line or at a specific address passed as an argument. A specified range can also allocate multiple chunks. A specified memory chunk can be released.

### Page Size
/lib/libarch/intel/IntelConstant.h:82
`/** Intel uses 4K pages. */
#define PAGESIZE        4096`

/lib/libarch/arm/ARMConstant.h:96
`/** ARM uses 4K pages. */
#define PAGESIZE        4096`

