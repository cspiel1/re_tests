#include <stdint.h>
#include <stdlib.h>
#include <re.h>
#include <errno.h>


int main(int argc, char *argv[])
{
	struct pl dest;
	struct sa localip;
	int err; /* errno return values */

	if (argc<2) {
		printf("Usage: %s IP\n", argv[0]);
		return EINVAL;
	}

	pl_set_str(&dest, argv[1]);

	err = net_if_getaddr_for(&dest, &localip, true);
	if (err)
		return EINVAL;

	re_printf("Local-IP: %j\n", &localip);

	return 0;
}
