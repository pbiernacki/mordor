#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>
#include <sys/conf.h>
#include <sys/uio.h>
#include <sys/malloc.h>

static char *read_msg = "one does not simply read from mordor\n";
static const int read_len = 38;
static struct cdev *mordor_dev;

static int
mordor_open(struct cdev *dev, int oflags, int devtype, struct thread *td)
{
    return (0);
}

static int
mordor_close(struct cdev *dev, int fflags, int devtype, struct thread *td)
{
    return (0);
}

static int
mordor_read(struct cdev *dev, struct uio *uio, int ioflag)
{
    int error;
    int i;

    i = MIN(uio->uio_resid,
            (read_len - uio->uio_offset > 0) ?
             read_len - uio->uio_offset : 0);
    error = uiomove(read_msg + uio->uio_offset, i, uio);

    return (error);
}

static struct cdevsw mordor_cdevsw = {
    .d_version = D_VERSION,
    .d_open = mordor_open,
    .d_close = mordor_close,
    .d_read = mordor_read,
    .d_name = "mordor"
};

static int
mordor_modevent(module_t mod __unused, int event, void *arg __unused)
{
    int error = 0;

    switch (event) {
    case MOD_LOAD:
        mordor_dev = make_dev(&mordor_cdevsw, 0, UID_ROOT, GID_WHEEL,
            0444, "mordor");
        uprintf("Mordor loaded\n");
        break;
    case MOD_UNLOAD:
        destroy_dev(mordor_dev);
        uprintf("Mordor unloaded\n");
        break;
    default:
        error = EOPNOTSUPP;
        break;
    }

    return (error);
}

DEV_MODULE(mordor, mordor_modevent, NULL);
