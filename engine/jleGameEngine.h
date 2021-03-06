#pragma once

#include "jleCore.h"

#include "jleGame.h"

#include "iFullscreenRendering.h"

namespace jle
{
	// Specifies which axis to be fixed, and the other scales depending on window aspect ratio
	enum class FIXED_AXIS { same_as_window, width, height };

	struct GameSettings : public CoreSettings
	{
		struct 
		{
			FIXED_AXIS fixedAxis{ FIXED_AXIS::same_as_window };
			unsigned int fixedAxisPixels{ 0 };
		} framebufferSettings;

		virtual ~GameSettings() {}
	};

	class jleGameEngine : public jle::jleCore
	{
	public:
		virtual ~jleGameEngine();

		jleGameEngine(std::shared_ptr<GameSettings> gs);
		
		template <class T>
		void SetGame() {
			gameCreator = std::make_unique<GameCreator<T>>();
		}

		// Main framebuffer
		std::shared_ptr<iFramebuffer> framebuffer_main;

		void SetGameDimsPixels(FIXED_AXIS fa, unsigned int pixels);

		std::pair<unsigned int, unsigned int> GetFramebufferDimensions(unsigned int windowWidth, unsigned int windowHeight);

		void StartGame();
		void KillGame();
		void HaltGame();
		void UnhaltGame();
		void ExecuteNextFrame();
		bool IsGameKilled();

		bool IsGameHalted();

		jleGame& GetGameRef();

	private:

		class iGameCreator
		{
		public:
			virtual ~iGameCreator() {}
			virtual std::unique_ptr<jleGame> CreateGame() = 0;
		};

		template <class T>
		class GameCreator : public iGameCreator {
		public:
			virtual ~GameCreator() {}
			virtual std::unique_ptr<jleGame> CreateGame() override
			{
				return std::make_unique<T>();
			}
		};

		std::unique_ptr<iGameCreator> gameCreator;

		std::unique_ptr<iFullscreenRendering> fullscreen_renderer;

		void FramebufferResizeEvent(unsigned int width, unsigned int height);
	protected:
		virtual void Start() override;
		virtual void Update(float dt) override;
		virtual void Render() override;
		virtual void Exiting() override;

		FIXED_AXIS fixed_axis;

		// Game dimensions in pixels, along axis specified by fixed_axis.
		unsigned int gameDimsPixels;

		std::unique_ptr<jleGame> game;
		bool gameHalted = false;
	};
}