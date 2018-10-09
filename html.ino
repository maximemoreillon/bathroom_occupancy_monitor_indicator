// Head elements

// Style
String styles = "<style>"
  "body{font-family: Verdana, Geneva, sans-serif; margin: 0px; background: #cccccc;}"
  ".wrapper{margin: 25px auto; width: 95%; max-width: 500px; background: white;	box-shadow: 0 10px 20px rgba(0,0,0,0.19), 0 6px 6px rgba(0,0,0,0.23);}"
  ".header{font-size: 32px; padding: 15px; color: white; background: DimGrey; box-shadow: 0 10px 20px rgba(0,0,0,0.19), 0 6px 6px rgba(0,0,0,0.23);}"
  ".main{padding: 15px;}"
  ".footer{text-align: center; padding: 10px; background: DarkGrey;	color: white;}"
  "</style>";

String head ="<head><title>telIoT</title>"+styles+"</head>";

// Body partials
String header = "<div class='header'>telIoT Indicator</div>";

String menu ="<h2>Menu</h2>"
  "<ul>"
  "<li><a href='/'>Status</a></li>"
  "<li><a href='/update_form'>Firmware update</a></li>"
  "<li><a href='/off'>Turn off</a></li>"
  "<li><a href='/party'>Party mode</a></li>"
  "</ul>";
  
String footer = "<div class='footer'> Maxime Moreillon </div>";

// Combination
String pre_main = "<html>" + head +"<body><div class='wrapper'>" + header + "<div class='main'>";
String post_main = menu + "</div>" + footer + "</div></body></html>";

// Root
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
