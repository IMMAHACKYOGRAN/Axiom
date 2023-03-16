#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Axiom {

	class AXIOM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define AX_CORE_TRACE(...)		::Axiom::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AX_CORE_INFO(...)		::Axiom::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AX_CORE_WARN(...)		::Axiom::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AX_CORE_ERROR(...)		::Axiom::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AX_CORE_CRITICAL(...)	::Axiom::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define AX_TRACE(...)			::Axiom::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AX_INFO(...)			::Axiom::Log::GetClientLogger()->info(__VA_ARGS__)
#define AX_WARN(...)			::Axiom::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AX_ERROR(...)			::Axiom::Log::GetClientLogger()->error(__VA_ARGS__)
#define AX_CRITICAL(...)		::Axiom::Log::GetClientLogger()->critical(__VA_ARGS__)