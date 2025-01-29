#include <iostream>
#include <inttypes.h>
#include <dpp/dpp.h>
#include <cstdlib>
#include "utils/env.h"
#include "database/sqlite.h"

using std::string;

int main()
{

	if (load_env() != 0)
		return 1;

	if (sqlite.open()) {
		std::cout << "Banco de dados conectado com sucesso." << std::endl;
	} else {
		return 1;
	};

	dpp::cluster bot(std::getenv("DISCORD_BOT_TOKEN"), dpp::i_guilds);

	bot.on_slashcommand([](auto event)
						{
		if (event.command.get_command_name() == "ping") {
			event.reply("Pong!");
		} });

	bot.on_ready([&bot](auto event)
				 {

		std::cout << "\x1b[32m[\x1b[36mDISCORD\x1b[32m] - Disconomy++ online!\x1b[0m\n";
		
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(
				dpp::slashcommand("ping", "Ping pong!", bot.me.id)
			);
	} });

	bot.start(dpp::st_wait);

	return 0;
}