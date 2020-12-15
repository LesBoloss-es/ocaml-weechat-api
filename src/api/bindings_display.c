#include "bindings.h"

#define CAML_NAME_SPACE
#include <caml/mlvalues.h> /* value */
#include <caml/memory.h> /* CAMLparam, CAMLxparam, CAMLlocal, CAMLreturn */


value caml_weechat_printf(value buffer, value message) {
  CAMLparam2(buffer, message);

  /* XXX. This is a stupid implementation of printf: format specifiers are
   * ignored. */
  weechat_printf(gui_buffer_unbox(buffer), "%s", String_val(message));

  CAMLreturn(Val_unit);
}
