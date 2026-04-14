#include <string>
#include <stack>
#include <assert.h>

using namespace std;

#include "solution.cpp"

int main(void)
{
    assert(Solution().isValid("()") == true);
    assert(Solution().isValid("()[]{}") == true);
    assert(Solution().isValid("(]") == false);
    assert(Solution().isValid("([])") == true);
    assert(Solution().isValid("([)]") == false);

    assert(Solution().isValid("[") == false);
    return 0;
}
