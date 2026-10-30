#ifndef WEB_THING_HTML_PAGES_H
#define WEB_THING_HTML_PAGES_H

#include "Arduino.h"

const char* HTTP_SELECTED = "selected";
const char* HTTP_CHECKED = "checked";
const char* HTTP_NONE = "none";
const char* HTTP_BLOCK = "block";
const char* HTTP_TRUE = "true";
const char* HTTP_FALSE = "false";
const char* VALUE_GET = "get";

const static char HTTP_TR[] PROGMEM = R"=====(<tr>)=====";
void tr(Print* page) { page->print(FPSTR(HTTP_TR)); }
const static char HTTP_TRE[] PROGMEM = R"=====(</tr>)=====";
void trEnd(Print* page) { page->print(FPSTR(HTTP_TRE)); }
const static char HTTP_TH[] PROGMEM = R"=====(<th>)=====";
void th(Print* page) { page->print(FPSTR(HTTP_TH)); }
const static char HTTP_THE[] PROGMEM = R"=====(</th>)=====";
void thEnd(Print* page) { page->print(FPSTR(HTTP_THE)); }
const static char HTTP_TD[] PROGMEM = R"=====(<td>)=====";
void td(Print* page) { page->print(FPSTR(HTTP_TD)); }
const static char HTTP_TDE[] PROGMEM = R"=====(</td>)=====";
void tdEnd(Print* page) { page->print(FPSTR(HTTP_TDE)); }

const static char HTTP_HEAD_BEGIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang='en'>
	<head>
		<meta name='viewport' content='width=device-width, initial-scale=1'/>
		<meta name='color-scheme' content='light dark'/>
		<title>%s</title>
)=====";

const static char HTTP_STYLE[] PROGMEM = R"=====(
<style>
:root{--bg:#f2f4f7;--card:#fff;--fg:#1d2433;--muted:#667085;--line:#d0d5dd;--field:#f9fafb;--accent:#0b72c6;--danger:#d92d20}
@media (prefers-color-scheme:dark){:root{--bg:#0f1218;--card:#1a1f29;--fg:#e6e9ef;--muted:#98a2b3;--line:#344054;--field:#11151c;--accent:#3d9be9;--danger:#f04438}}
*{box-sizing:border-box}
body{margin:0;padding:16px;background:var(--bg);color:var(--fg);font:16px/1.45 system-ui,-apple-system,'Segoe UI',Roboto,sans-serif;text-align:center}
.mc{display:inline-block;width:100%;max-width:560px;text-align:left;background:var(--card);border-radius:14px;padding:20px;box-shadow:0 1px 3px rgba(0,0,0,.08),0 8px 24px rgba(0,0,0,.06)}
.mc .mc{display:block;max-width:none;padding:0;box-shadow:none;border-radius:0}
div{padding:6px 0}
h2{margin:0 0 2px;font-size:1.4rem}
h3{display:inline-block;margin:0 14px 12px 0;font-size:.85rem;font-weight:400;color:var(--muted)}
button,.cbtn{width:100%;border:0;border-radius:9px;background:var(--accent);color:#fff;font:inherit;font-weight:600;padding:11px 14px;cursor:pointer}
button:hover{filter:brightness(1.1)}
.cbtn{background:var(--danger)}
input,select{font:inherit;color:inherit;background:var(--field);border:1px solid var(--line);border-radius:9px;padding:9px 10px}
.ip{width:100%;margin-top:4px}
input:focus,select:focus{outline:2px solid var(--accent);outline-offset:1px}
label{display:inline-flex;gap:10px;align-items:flex-start;cursor:pointer}
input[type=checkbox],input[type=radio]{width:18px;height:18px;margin:3px 0 0;padding:0;accent-color:var(--accent);flex:none}
table{border-collapse:collapse;width:100%}
th,td{padding:6px 4px;text-align:left}
th{font-weight:600;color:var(--muted)}
.st,.tt{margin:0 auto}
.st th,.st td{border:1px solid var(--line);text-align:center;font-size:.9rem}
.st td{font-size:.75rem;color:var(--muted)}
.st input[type=text]{display:block;width:64px;padding:5px;margin:2px auto 6px;text-align:center;font-size:.9rem;color:var(--fg)}
a{color:var(--accent)}
h2 a{color:inherit;text-decoration:none}
</style>
)=====";

const static char HTTP_HEAD_END[] PROGMEM = R"=====(
	</head>
	<body>
		<div class='mc'>
)=====";

const static char HTTP_BODY_END[] PROGMEM = R"=====(
		</div>
	</body>
</html>
)=====";

const static char HTTP_BUTTON[] PROGMEM = R"=====(
	<div>
  	<form action='/%s' method='%s'>
    	<button>%s</button>
    </form>
  </div>
)=====";

const static char HTTP_BUTTON_ALERT[] PROGMEM = R"=====(
	<div>
  	<form action='/%s' method='%s'>
    	<button class='cbtn'>%s</button>
    </form>
  </div>
)=====";

const static char HTTP_BUTTON_SUBMIT[] PROGMEM = R"=====(
		<div>
			<button type='submit'>%s</button>
		</div>
</form>
)=====";

const static char HTTP_CONFIG_SAVE_BUTTON[] PROGMEM = R"=====(
		<div>
			<button type='submit'>Save configuration</button>
		</div>
</form>
)=====";

const static char HTTP_DIV_BEGIN[] PROGMEM = R"=====(
	<div>
)=====";

const static char HTTP_DIV_ID_BEGIN[] PROGMEM = R"=====(
	<div id='%s'>
)=====";

const static char HTTP_DIV_END[] PROGMEM = R"=====(
	</div>
)=====";

const static char HTTP_TOGGLE_FUNCTION_SCRIPT[] PROGMEM = R"=====(
	<script>
		function %s {
			var sa = document.getElementById('%s');
			var ga = document.getElementById('%s');
			ga.style.display = (sa.checked ? 'block' : 'none');
			var gb = document.getElementById('%s');
			if (gb != null && gb !== undefined) {
				gb.style.display = (sa.checked ? 'none' : 'block');
			}
		}
	</script>
)=====";

const static char HTTP_TOGGLE_GROUP_STYLE[] PROGMEM = R"=====(
<style>
#%s {
  display:%s;
}
#%s {
	display:%s;
}
</style>
)=====";

const static char HTTP_SAVED[] PROGMEM = R"=====(
<div>
	%s
</div>
<div>
	ESP reboots now...
</div>
<div>
	<form action='/config' method='get'>
		<button>Back to configuration</button>
	</form>
</div>
)=====";

const static char HTTP_FORM_FIRMWARE[] PROGMEM = R"=====(
<form method='POST' action='' enctype='multipart/form-data'>
	<div>
  	<input type='file' accept='.bin' name='update'>
  </div>
  <div>
		<button type='submit' class='cbtn'>Update firmware</button>
  </div>
</form>
)=====";

const static char HTTP_CONFIG_PAGE_BEGIN[] PROGMEM = R"=====(
<form method='get' class='mc' action='submit%s'>
)=====";

const static char HTTP_INPUT_FIELD[] PROGMEM = R"=====(
	<input type='text' name='%s' maxlength='%s' value='%s'>
)=====";

const static char HTTP_TEXT_FIELD[] PROGMEM = R"=====(
	<div>
		%s<br>
		<input type='text' class='ip' name='%s' maxlength='%s' value='%s'>
	</div>
)=====";

const static char HTTP_PASSWORD_FIELD[] PROGMEM = R"=====(
	<div>
		%s<br>
		<input type='password' class='ip' name='%s' length=%s value='%s'>
	</div>
)=====";

const static char HTTP_CHECKBOX[] PROGMEM = R"=====(
		<div>
			<label>
				<input type='checkbox' name='%s' value='true' %s>%s
			</label>
		</div>
)=====";

const static char HTTP_CHECKBOX_OPTION[] PROGMEM = R"=====(
	<div>
		<label>
			<input type='checkbox' id='%s' name='%s' value='true' %s onclick='%s'>%s
		</label>
	</div>
)=====";

const static char HTTP_RADIO_OPTION[] PROGMEM = R"=====(
	<label>
		<input type='radio' id='%s' name='%s' value='%s' %s onclick='%s'>%s
	</label>
)=====";

const static char HTTP_COMBOBOX_BEGIN[] PROGMEM = R"=====(
        <div>
			%s<br>
        	<select class='ip' name='%s'>
)=====";

const static char HTTP_COMBOBOX_ITEM[] PROGMEM = R"=====(
				<option class='ip' value='%s' %s>%s</option>
)=====";
const static char HTTP_COMBOBOX_END[] PROGMEM = R"=====(
			</select>
        </div>
)=====";

class WHtml {
 public:

	static void checkBox(Print* page, const char* id, const char* title, bool checked) {
		page->printf(HTTP_CHECKBOX_OPTION, id, id, (checked ? HTTP_CHECKED : ""), "", title);
	}

	static void comboBoxBegin(Print* page, const char* id, const char* title) {
		page->printf(HTTP_COMBOBOX_BEGIN, title, id);
	}

	static void comboBoxEnd(Print* page) {
		page->print(FPSTR(HTTP_COMBOBOX_END));
	}

	static void comboBoxItem(Print* page, const char* title, const char* value, bool selected) {
    page->printf(HTTP_COMBOBOX_ITEM, value, (selected ? HTTP_SELECTED : ""), title);
  }

  static void textField(Print* page, const char* fieldName, const char* title, byte maxLength, const char* value) {
	page->printf(HTTP_TEXT_FIELD, title, fieldName, String(maxLength).c_str(), value);
  }

};

#endif
