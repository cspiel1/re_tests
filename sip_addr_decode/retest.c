#include <stdint.h>
#include <stdlib.h>
#include <re.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	struct pl pl;
	struct sip_addr addr;
	struct uri *uri;

	int err; /* errno return values */

	uri = &addr.uri;

	if (argc<2) {
		printf("Usage: %s sipaddr\n", argv[0]);
		return EINVAL;
	}

	memset(&addr, 0, sizeof(addr));
	pl_set_str(&pl, argv[1]);
	err = sip_addr_decode(&addr, &pl);

	if (err) {
		re_printf("SIP addr decode error: %m.\n", err);
		return err;
	}

	re_printf("Dial string: %r\n", &pl);

	re_printf("SIP Addr:\n");
	re_printf("  dname  : %r\n", &addr.dname);
	re_printf("  auri   : %r\n", &addr.auri);
	re_printf("  params : %r\n", &addr.params);
	re_printf("  URI:\n");
	re_printf("    scheme   : %r\n", &uri->scheme);
	re_printf("    user     : %r\n", &uri->user);
	re_printf("    password : %r\n", &uri->password);
	re_printf("    host     : %r\n", &uri->host);
	re_printf("    af       : %d\n", &uri->af);
	re_printf("    port     : %d\n", &uri->port);
	re_printf("    params   : %r\n", &uri->params);
	re_printf("    headers  : %r\n", &uri->headers);

	return 0;
}
