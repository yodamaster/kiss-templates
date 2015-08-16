%namespace test
%{
  $class Sample

  %auto linkTarget(const std::string& target) const -> void
  %{
    %if (not target.empty())
    %{
      $|target="${target}"$|
    %}
  %}

  %auto render() const -> void
  %{
    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
    <HTML>
      <HEAD>
        <TITLE>
          ${data.documentTitle}
        </TITLE>
      </HEAD>
      <BODY bgcolor="${data.backgroundColor}">
      <h1>${data.documentTitle}</h1>

      <FORM NAME="form" ACTION="${data.formUrl}" METHOD="POST" $call{linkTarget(data.formTarget)}>
        %for (auto param : data.params)
        %{
          <INPUT TYPE="${param.type}" NAME="${param.name}" VALUE="${param.value}"><br/>
        %}
      </FORM>
      </BODY>
    </HTML>
  %}

  $endclass
%}