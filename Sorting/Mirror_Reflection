class Solution:
    def mirror_reflection(self, p: int, q: int) -> int:
        # Constraints
        assert 1 <= q <= p <= 1000
        # Edge Cases
        if p == q:
            return 1
        if q == 0:
            return 0
        if p == 0:
            return 2
        # Algorithm
        # Divide p,q by 2 until at least one becomes odd.
        while p % 2 == 0 and q % 2 == 0:
            p //= 2
            q //= 2
        # when p is odd and q is odd
        if p % 2 == 1:
            return q % 2
        # when p is even and q is odd
        return 2


MirrorReflection = Solution

__all__ = ["MirrorReflection"]
