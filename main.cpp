
#include "app/bs_root.h"
#include "core/os/platform.h"
#include "core/settings/settings.h"
#include "database/database_manager.h"
#include "database_modules/db_settings/db_settings.h"
#include "web/file_cache.h"
#include "web/http/session_manager.h"
#include "web_backends/drogon/drogon_web_server.h"

#include "rcpp_framework.h"

int main(int argc, char **argv, char **envp) {
	RCPPFramework::create_and_init(argc, argv, envp);
	RCPPFramework::get_singleton()->www_root = "./www/";

	DrogonWebServer *app = new DrogonWebServer();
	RCPPFramework::get_singleton()->manage_object(app);

	BSRoot *app_root = new BSRoot();
	app_root->setup();

	app->set_root(app_root);

	app->add_listener("127.0.0.1", 8080);
	RLOG_MSG("Server running on 127.0.0.1:8080");

	RCPPFramework::get_singleton()->load();

	RLOG_MSG("Initialized!\n");
	app->run();

	RCPPFramework::destroy();

	return 0;
}