#include <iostream>
#include <inttypes.h>
#include <dpp/dpp.h>
#include <cstdlib>
#include "utils/env.h"
#include "utils/log.h"
#include "database/sqlite.h"

using std::string;

int main()
{

	if (load_env() != 0)
		return 1;

	if (sqlite.open())
	{
		log(LogLevel::INFO, "DATABASE", "Connected to database succesfully.");
	}
	else
	{
		log(LogLevel::INFO, "DATABASE", "Can't connect to database. Shutting Down.");
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

		log(LogLevel::INFO, "DISCORD", "Disconomy++ online!");
		
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(
				dpp::slashcommand("ping", "Ping pong!", bot.me.id)
			);
	} });

	bot.start(dpp::st_wait);

	return 0;
}