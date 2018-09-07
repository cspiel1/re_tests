#include <stdint.h>
#include <stdlib.h>
#include <re.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	struct pl uristr;
	struct uri uri;

	int err; /* errno return values */

	if (argc<2) {
		printf("Usage: %s uristr\n", argv[0]);
		return EINVAL;
	}

	memset(&uri, 0, sizeof(uri));
	pl_set_str(&uristr, argv[1]);
	err = uri_decode(&uri, &uristr);

	if (err) {
		re_printf("URI decode error: %m.\n", err);
		return err;
	}

	re_printf("Dial string: %r\n", &uristr);

	re_printf("URI:\n");
	re_printf("   scheme   : %r\n", &uri.scheme);
	re_printf("   user     : %r\n", &uri.user);
	re_printf("   password : %r\n", &uri.password);
	re_printf("   host     : %r\n", &uri.host);
	re_printf("   af       : %d\n", &uri.af);
	re_printf("   port     : %d\n", &uri.port);
	re_printf("   params   : %r\n", &uri.params);
	re_printf("   headers  : %r\n", &uri.headers);

	return 0;
}
