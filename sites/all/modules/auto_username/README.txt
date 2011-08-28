ABOUT

This module disables the "Username" field on user registration and user edit
forms and generates a username automatically using a token.module-provided pattern.
That allows for usernames that are, for instance, forced to be "Lastname, Firstname",
"Firstname Last-initial", etc.

auto_username depends on token.module.


REQUIREMENTS

- Drupal 6.x
- Token module

CONFIGURATION

Once the module is enabled, go to admin/user/auto-username to configure the module.

AUTHOR AND CREDIT

Maintainer:
Larry Garfield
http://www.palantir.net/

Porting to Drupal 6.x:
Fabio Varesano
http://www.varesano.net/

This module was initially developed by Palantir.net and released to the Drupal
community under the GNU General Public License.
