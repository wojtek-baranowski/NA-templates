#include <catch.hpp>

#include "stm.h"

namespace events
{
    struct begin {};
    struct end {};
    struct pause {};
    struct resume {};
    struct exit {};
}

namespace states
{
    struct exited
    {
    };

    struct paused
    {
        auto handle(events::resume);
        auto handle(events::end);
    };

    struct active
    {
        auto handle(events::pause)
        {
            return paused{};
        }

        auto handle(events::end);
    };

    struct inactive
    {
        auto handle(events::exit)
        {
            return exited{};
        }

        auto handle(events::begin)
        {
            return active{};
        }
    };

    auto active::handle(events::end)
    {
        return inactive{};
    }

    auto paused::handle(events::resume)
    {
        return active{};
    }

    auto paused::handle(events::end)
    {
        return inactive{};
    }
}

TEST_CASE("state machine transitions", "[stm]")
{
    state_machine<states::inactive, states::active, states::paused, states::exited> stm{ states::inactive{} };

    REQUIRE(stm.is_active<states::inactive>());

    stm.raise(events::begin{});
    REQUIRE(stm.is_active<states::active>());

    stm.raise(events::pause{});
    REQUIRE(stm.is_active<states::paused>());

    REQUIRE_THROWS_AS(stm.raise(events::begin{}), invalid_transition);

    stm.raise<events::resume>();
    REQUIRE(stm.is_active<states::active>());

    stm.raise<events::end>();
    REQUIRE(stm.is_active<states::inactive>());

    stm.raise(events::exit{});
    REQUIRE(stm.is_active<states::exited>());
}

