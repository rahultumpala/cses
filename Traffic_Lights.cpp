#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
	set<int> lights;
	map<int, int> distances;
	lights.insert(0);
	lights.insert(x);
	distances[x]++;
	for(int i=0; i < n; i++){
		int light;
		cin >> light;
		lights.insert(light);
		auto iter = lights.find(light);
		int prev_light = *prev(iter);
		int next_light = *next(iter);
		distances[next_light - prev_light]--;
		if(distances[next_light - prev_light] == 0) distances.erase(next_light - prev_light);
		distances[light - prev_light]++;
		distances[next_light - light]++;
		cout << distances.rbegin()->first << " ";
	}
    return 0;
}
