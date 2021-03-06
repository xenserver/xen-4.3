#include <xen/config.h>
#include <asm/system.h>
#include <asm/smp.h>
#include <asm/cpregs.h>
#include <asm/page.h>
#include <asm/gic.h>

void flush_tlb_mask(const cpumask_t *mask)
{
    /* No need to IPI other processors on ARM, the processor takes care of it. */
    flush_xen_data_tlb();
}

void smp_send_event_check_mask(const cpumask_t *mask)
{
    send_SGI_mask(mask, GIC_SGI_EVENT_CHECK);
}

void smp_send_call_function_mask(const cpumask_t *mask)
{
    send_SGI_mask(mask, GIC_SGI_CALL_FUNCTION);
}

/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 */
