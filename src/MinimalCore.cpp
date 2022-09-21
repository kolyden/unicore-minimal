#include "MinimalCore.hpp"
#include "unicore/Input.hpp"
#include "unicore/Time.hpp"
#include "unicore/xml/XMLPlugin.hpp"
#include "unicore/fnt/FNTPlugin.hpp"

namespace unicore
{
	MinimalCore::MinimalCore(const CoreSettings& settings)
		: SDLCore(create_settings(settings, "Player"))
	{
		create_plugin<XMLPlugin>();
		create_plugin<FNTPlugin>();
	}

	void MinimalCore::on_init()
	{
	}

	void MinimalCore::on_update()
	{
		if (input.keyboard().down(KeyCode::Escape))
			platform.quit();

		_sprite_batch.clear();

		_sprite_batch.flush();
	}

	void MinimalCore::on_draw()
	{
		const auto t = Math::abs(Math::sin(time.elapsed().total_seconds()));
		const auto color = static_cast<Byte>(Math::round_to_int(255 * t));
		renderer.clear(Color4b(color, color, color));

		_sprite_batch.render(renderer);
	}
}