#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/prime.hpp"

TEST_CASE("prime returns correct prime factors") {
    Factorizer factorizer;

    SECTION("Numbers <= 1 return empty vector") {
        REQUIRE(factorizer.prime(0).empty());
        REQUIRE(factorizer.prime(1).empty());
        REQUIRE(factorizer.prime(-5).empty());
    }

    SECTION("Prime numbers return themselves") {
        REQUIRE(factorizer.prime(2) == std::vector<int>{2});
        REQUIRE(factorizer.prime(3) == std::vector<int>{3});
        REQUIRE(factorizer.prime(17) == std::vector<int>{17});
    }

    SECTION("numbers return correct factors") {
        REQUIRE(factorizer.prime(4) == std::vector<int>{2, 2});
        REQUIRE(factorizer.prime(6) == std::vector<int>{2, 3});
        REQUIRE(factorizer.prime(9) == std::vector<int>{3, 3});
        REQUIRE(factorizer.prime(10) == std::vector<int>{2, 5});
        REQUIRE(factorizer.prime(60) == std::vector<int>{2, 2, 3, 5});
    }
}