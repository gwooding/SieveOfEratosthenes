#define CATCH_CONFIG_MAIN
#include "Catch.h"
#include "Sieve.h"

TEST_CASE("Exception handling for silly input", "") {

    REQUIRE_THROWS_WITH(findPrimesUnder(0), "n needs to be above zero");
    REQUIRE_THROWS_WITH(findPrimesUnder(-1), "n needs to be above zero");
}

TEST_CASE("Null response for 1 and 2 upper limits") {

    REQUIRE_FALSE(findPrimesUnder(1));
    REQUIRE_FALSE(findPrimesUnder(2));

}

TEST_CASE("Expected result when n is 3"){

	REQUIRE(findPrimesUnder(3)[0] == false);
    REQUIRE(findPrimesUnder(3)[1] == false);
    REQUIRE(findPrimesUnder(3)[2] == true);
}

TEST_CASE("Expected result when n is 5"){

    REQUIRE(findPrimesUnder(5)[0] == false);
    REQUIRE(findPrimesUnder(5)[1] == false);
    REQUIRE(findPrimesUnder(5)[2] == true);
    REQUIRE(findPrimesUnder(5)[3] == true);
    REQUIRE(findPrimesUnder(5)[4] == false);
}