# CS 4310 - FreeNOS
- Andrew Arteaga
- Sergey Hambardzumyan
- Zane Reis
## Memory Management
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

