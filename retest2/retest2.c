#include <stdint.h>
#include <stdlib.h>
#include <re.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	struct pl viastr;
	struct sip_via via;
	int err; /* errno return values */

	if (argc<2) {
		printf("Usage: %s viastr\n", argv[0]);
		return EINVAL;
	}

	memset(&via, 0, sizeof(via));
	pl_set_str(&viastr, argv[1]);
	err = sip_via_decode(&via, &viastr);

	if (err) {
		re_printf("Via decode error: %m.\n", err);
		return err;
	}

	re_printf("Via:\n");
	re_printf("   sentby   : %r\n", &via.sentby);
	re_printf("   addr     : %j\n", &via.addr);
	re_printf("   params   : %r\n", &via.params);
	re_printf("   branch   : %r\n", &via.branch);
	re_printf("   val      : %r\n", &via.val);
	re_printf("   received : %J is_set=%d\n", &via.received, sa_isset(&via.received, SA_ALL));
	re_printf("   tp       : %s\n", sip_transp_name(via.tp));

	return 0;
}
