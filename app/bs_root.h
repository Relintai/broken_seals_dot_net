#ifndef BS_ROOT_H
#define BS_ROOT_H

//#include "web/http/web_application.h"
#include "core/object.h"
#include "web/http/web_root.h"

#undef LOG_TRACE
#undef LOG_WARN

#include "web_modules/list_page/list_page.h"
#include "web_modules/message_page/message_page.h"
#include "web_modules/paged_article/paged_article.h"
#include "web_modules/paged_article/paged_articles.h"
#include "web_modules/paged_article/paged_articles_md_index.h"

class AdminPanel;
class UserController;
class MenuNode;
class PageManager;

class BSRoot : public WebRoot {
	RCPP_OBJECT(BSRoot, WebRoot);

public:
	void _handle_request_main(Request *request);

	void _render_menu(Request *request);

	bool is_logged_in(Request *request);

	void compile_menu();

	BSRoot();
	~BSRoot();

	static String menu_head;
	static String footer;
};

#endif