// Head elements

// Style
String styles = "<style>"
  "body{font-family: Verdana, Geneva, sans-serif; margin: 0px; background: #cccccc;}"
  ".wrapper{margin: 25px auto; width: 95%; max-width: 500px; background: white;	box-shadow: 0 10px 20px rgba(0,0,0,0.19), 0 6px 6px rgba(0,0,0,0.23);}"
  ".header{ padding: 15px; color: white; background: DimGrey; box-shadow: 0 10px 20px rgba(0,0,0,0.19), 0 6px 6px rgba(0,0,0,0.23);}"
  ".main{padding: 15px;}"
  ".nav{padding: 15px;}"
  "table{width: 100%; border-collapse: collapse;}"
  "table, th, td {border: 1px solid black; text-align: center;}"
  "form{text-align:center;}"
  ".footer{text-align: center; padding: 10px; background: DarkGrey;	color: white;}"
  "</style>";

String head ="<head><title>telIoT</title>"+styles+"</head>";

// Body partials
String header = "<div class='header'>"
  "<h1>telIoT Indicator</h1>"
  "</div>";

String nav = "<div class='nav'>"
  "<h2>Menu</h2>"
  "<ul>"
  "<li><a href='/'>Status</a></li>"
  "<li><a href='/update_form'>Firmware update</a></li>"
  "</ul>"
  "</div>";
  
String footer = "<div class='footer'> Maxime Moreillon </div>";

// Combinations
String pre_main = "<html>" + head +"<body><div class='wrapper'>" + header + "<div class='main'>";
String post_main = "</div>" + nav + footer + "</div></body></html>";

// Root (currently not used)
String root_main = "<div id='status_container'>"
  "UNDEFINED"
  "</div>"
  "<script>"
  "websock = new WebSocket('ws://' + window.location.hostname + ':81/');"
  "websock.onopen = function(evt) { console.log('websock open'); };"
  "websock.onclose = function(evt) { console.log('websock close'); };"
  "websock.onerror = function(evt) { console.log(evt); };"
  "websock.onmessage = function(evt) {"
  "  console.log(evt);"
  "  var status_container = document.getElementById('status_container');"
  "  if (evt.data === 'occupied') {"
  "    status_container.innerText = 'OCCUPIED'"
  "  }"
  "  else if (evt.data === 'vacant') {"
  "    status_container.innerText = 'VACANT'"
  "  }"
  "  else {"
  "    console.log('unknown event');"
  "  }"
  "};"
  "</script>";
  

// Update form
String update_form = "<h2>Firmware update</h2>"
  "<form method='POST' action='/update' enctype='multipart/form-data'>"
  "<input type='file' name='update'>"
  "<input type='submit' value='Update'>"
  "</form>";
