
#include <string>
#include <unordered_set>
#include <vector>



class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folders) {
		std::vector<std::string> result;
		std::unordered_set<std::string_view> set(folders.begin(), folders.end());

		for (const auto& folder : folders) {
			bool isSubfolder = false;

			for (int i = 2; i < folder.size(); ++i) {
				if (folder[i] == '/' && set.count(std::string_view(folder.c_str(), i))) {
					isSubfolder = true;
					break;
				}
			}

			if (!isSubfolder)
				result.emplace_back(folder);
		}

		return result;
    }
};
