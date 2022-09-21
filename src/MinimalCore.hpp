#pragma once
#include "unicore/app/SDLCore.hpp"
#include "unicore/SpriteBatch.hpp"

namespace unicore
{
	class MinimalCore : public SDLCore
	{
	public:
		explicit MinimalCore(const CoreSettings& settings);

	protected:
		SpriteBatch _sprite_batch;

		void on_init() override;
		void on_update() override;
		void on_draw() override;
	};
}