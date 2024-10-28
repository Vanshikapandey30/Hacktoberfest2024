function minWindow(s, t) {
    if (s.length === 0 || t.length === 0) {
        return "";
    }

    // Frequency map for characters in t
    const tMap = {};
    for (let char of t) {
        tMap[char] = (tMap[char] || 0) + 1;
    }

    let required = Object.keys(tMap).length; // Number of unique characters in t that must be present in the window

    // Left and right pointers for the window
    let left = 0, right = 0;
    let formed = 0; // To keep track of the characters in the current window that match tMap

    // To keep track of characters in the current window
    const windowCounts = {};

    // Result tuple (window length, left, right)
    let ans = [-1, 0, 0]; // [window length, left, right]

    while (right < s.length) {
        // Add one character from the right to the window
        let char = s[right];
        windowCounts[char] = (windowCounts[char] || 0) + 1;

        // If the frequency of the current character matches the frequency in tMap, increment `formed`
        if (tMap[char] && windowCounts[char] === tMap[char]) {
            formed++;
        }

        // Try to contract the window from the left, as long as it's valid
        while (left <= right && formed === required) {
            char = s[left];

            // Update the result if this window is smaller than the previous best
            if (ans[0] === -1 || (right - left + 1) < ans[0]) {
                ans = [right - left + 1, left, right];
            }

            // The character at `left` is no longer part of the window
            windowCounts[char]--;
            if (tMap[char] && windowCounts[char] < tMap[char]) {
                formed--;
            }

            // Move the left pointer to contract the window
            left++;
        }

        // Move the right pointer to expand the window
        right++;
    }

    return ans[0] === -1 ? "" : s.slice(ans[1], ans[2] + 1);
}
