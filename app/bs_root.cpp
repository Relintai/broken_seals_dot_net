#include "bs_root.h"

#include "web/http/request.h"
#include "web/html/html_builder.h"

void BSRoot::_handle_request_main(Request *request) {
	_render_menu(request);

	request->body += "test";
	request->compile_and_send_body();
}

void BSRoot::_render_menu(Request *request) {
	request->head += menu_head;

	HTMLBuilder b;
	HTMLTag *t;

	b.div("content");

	b.ul()->cls("menu");
	{
		b.li();

		t = b.a()->href("/");
		b.w("TSITE");
		b.ca();
		b.cli();
	}
	b.cul();

	b.div("main");
	b.write_tag();

	request->body += b.result;
	request->footer = footer;
}

void BSRoot::compile_menu() {
	HTMLBuilder bh;

	bh.meta()->charset_utf_8();

	bh.link()->rel_stylesheet()->href("/css/main.css");
	bh.write_tag();

	menu_head = bh.result;

	HTMLBuilder bf;

	bf.cdiv();
	bf.footer();
	bf.w("Powered by ");
	bf.a()->href("https://github.com/Relintai/rcpp_cms");
	bf.w("rcpp cms");
	bf.ca();
	bf.w(".");
	bf.cfooter();

	bf.cdiv();

	footer = bf.result;
}

BSRoot::BSRoot() :
		WebRoot() {

	compile_menu();
}

BSRoot::~BSRoot() {
}

String BSRoot::menu_head = "";
String BSRoot::footer = "";
