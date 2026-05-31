class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        curr_mass = mass

        for asteroid in asteroids:
            if curr_mass < asteroid:
                return False

            curr_mass += asteroid

        return True
