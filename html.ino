// Head elements

// Style
const String styles = "<style>"
  "body{display: flex; justify-content: center; align-items: flex-start; font-family: Verdana, Geneva, sans-serif; margin: 0px; background: #cccccc;}"
  ".wrapper{margin: 25px; width: 100%; max-width: 500px; background: white;  box-shadow: 0 10px 20px rgba(0,0,0,0.19), 0 6px 6px rgba(0,0,0,0.23);}"
  "header{padding: 15px; color: white; background: DimGrey;}"
  "main{padding: 15px;}"
  "nav{padding: 15px;}"
  "form{text-align:center;}"
  "footer{text-align: center; padding: 10px; background: DarkGrey; color: white;}"
  "table{width: 100%; border-collapse: collapse;}"
  "table, th, td {border: 1px solid black; text-align: center;}"
  "</style>";


// Body partials
const String header = "<header>"
  "<h1>TelIoT indicator</h1>"
  "</header>";

const String nav = "<nav>"
  "<h2>Menu</h2>"
  "<ul>"
  "<li><a href='/'>Status</a></li>"
  "<li><a href='/update_form'>Firmware update</a></li>"
  "</ul>"
  "</nav>";
  
const String footer = "<footer> Maxime Moreillon </footer>";

// Combinations
String head ="<head>"
  "<title>telIoT</title>"
  + styles +
  "</head>";
  
String pre_main = "<html>"
  + head +
  "<body>"
  "<div class='wrapper'>"
  + header +
  "<main>";
  
String post_main = "</main>"
  + nav + footer +
  "</div>"
  "</body>"
  "</html>";

