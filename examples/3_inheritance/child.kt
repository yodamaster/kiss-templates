%#include <parent.h>

%namespace test
%{
  $class Child : Parent

  %auto body() const -> void
  %{
    Child header.

    %// Calling the child's child
    $call{child.body()}

    Child footer
  %}

  $endclass
%}
