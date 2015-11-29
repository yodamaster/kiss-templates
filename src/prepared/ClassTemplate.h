// generated by kiste2cpp
#pragma once
#include <kiste/terminal.h>

#line 1 "../src/ClassTemplate.kiste"
namespace kiste
{
template<typename DERIVED_T, typename DATA_T, typename SERIALIZER_T>
struct ClassTemplate_t
{
  DERIVED_T& child;
  using _data_t = DATA_T;
  const _data_t& data;
  using _serializer_t = SERIALIZER_T;
  _serializer_t& _serialize;

  ClassTemplate_t(DERIVED_T& derived, const DATA_T& data_, SERIALIZER_T& serialize):
    child(derived),
    data(data_),
    _serialize(serialize)
  {}
  // ----------------------------------------------------------------------
#line 4

    void line_directive(const size_t line_no)
    {
      if (data._line_directives)
      {
        _serialize.text("#line "); _serialize.escape(line_no); _serialize.text("");
      }
    }

    template<typename ClassData>
    void render_header(const size_t line_no, const ClassData& class_data)
    {
      _serialize.text("template<typename DERIVED_T, typename DATA_T, typename SERIALIZER_T>\n"
             "struct "); _serialize.escape(class_data._name); _serialize.text("_t\n");
      if (!class_data._parent_name.empty())
      {
        _serialize.text("  : public "); _serialize.escape(class_data._parent_name); _serialize.text("_t<"); _serialize.escape(class_data._name); _serialize.text("_t<DERIVED_T, DATA_T, SERIALIZER_T>, DATA_T, SERIALIZER_T>\n");
      }
      _serialize.text("{\n");
      if (!class_data._parent_name.empty())
      {
        _serialize.text("  using _parent_t = "); _serialize.escape(class_data._parent_name); _serialize.text("_t<"); _serialize.escape(class_data._name); _serialize.text("_t, DATA_T, SERIALIZER_T>;\n"
               "  _parent_t& parent;\n");
      }
      _serialize.text("  DERIVED_T& child;\n"
             "  using _data_t = DATA_T;\n"
             "  const _data_t& data;\n"
             "  using _serializer_t = SERIALIZER_T;\n"
             "  _serializer_t& _serialize;\n"
             "\n"
             "    "); _serialize.escape(class_data._name); _serialize.text("_t(DERIVED_T& derived, const DATA_T& data_, SERIALIZER_T& serialize):\n");
      if (!class_data._parent_name.empty())
      {
        _serialize.text("    _parent_t{*this, data_, serialize},\n"
               "    parent(*this),\n");
      }
      _serialize.text("    child(derived),\n"
             "    data(data_),\n"
             "    _serialize(serialize)\n"
             "  {}\n"
             ""); static_assert(std::is_same<decltype(line_directive(line_no + 1)), void>::value, "$call{} requires void expression"); (line_directive(line_no + 1)); _serialize.text("\n");
    }

    template<typename ClassData, typename Member>
    void render_member(const size_t line_no, const ClassData& class_data, const Member& member)
    {
      // The "using" is required for clang-3.1 and older g++ versions
      auto class_alias = member.class_name + "_t_alias";
      _serialize.text("using "); _serialize.escape(class_alias); _serialize.text(" = "); _serialize.escape(member.class_name); _serialize.text("_t<"); _serialize.escape(class_data._name); _serialize.text("_t, _data_t, _serializer_t>;"
             ""); _serialize.escape(class_alias); _serialize.text(" "); _serialize.escape(member.name); _serialize.text(" = "); _serialize.escape(class_alias); _serialize.text("{*this, data, _serialize};\n"
             ""); static_assert(std::is_same<decltype(line_directive(line_no + 1)), void>::value, "$call{} requires void expression"); (line_directive(line_no + 1)); _serialize.text("\n");
    }

    template<typename ClassData>
    void render_footer(const size_t line_no, const ClassData& class_data)
    {
      _serialize.text(""); static_assert(std::is_same<decltype(line_directive(line_no)), void>::value, "$call{} requires void expression"); (line_directive(line_no)); _serialize.text("\n"
             "};\n"
             "\n"
             ""); static_assert(std::is_same<decltype(line_directive(line_no)), void>::value, "$call{} requires void expression"); (line_directive(line_no)); _serialize.text("\n"
             "template<typename DATA_T, typename SERIALIZER_T>\n"
             "auto "); _serialize.escape(class_data._name); _serialize.text("(const DATA_T& data, SERIALIZER_T& serialize)\n"
             "  -> "); _serialize.escape(class_data._name); _serialize.text("_t<kiste::terminal_t, DATA_T, SERIALIZER_T>\n"
             "{\n"
             "  return {kiste::terminal, data, serialize};\n"
             "}\n"
             "\n"
             ""); static_assert(std::is_same<decltype(line_directive(line_no)), void>::value, "$call{} requires void expression"); (line_directive(line_no)); _serialize.text("\n");
    }

  // ----------------------------------------------------------------------
#line 74
};

#line 74
template<typename DATA_T, typename SERIALIZER_T>
auto ClassTemplate(const DATA_T& data, SERIALIZER_T& serialize)
  -> ClassTemplate_t<kiste::terminal_t, DATA_T, SERIALIZER_T>
{
  return {kiste::terminal, data, serialize};
}

#line 75
}

