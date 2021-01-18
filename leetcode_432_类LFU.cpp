#include<string>
#include<list>
#include<unordered_map>
using namespace std;
class AllOne {
private:
	class Node {
	public:
		list<pair<int, list<string>>>::iterator iter_value;
		list<string>::iterator iter_key;
	public:
		Node(list<pair<int, list<string>>>::iterator iter_value, list<string>::iterator iter_key)
			:iter_value(iter_value), iter_key(iter_key){}
	};
	unordered_map<string, Node*> key_node;
	list<pair<int, list<string>>> key_list;

public:
	/** Initialize your data structure here. */
	AllOne() {

	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		auto iter = key_node.find(key);
		if (iter != key_node.end()) {
			auto iter_buff = iter->second->iter_value;
			iter_buff++;
			iter->second->iter_value->second.erase(iter->second->iter_key);
			// 如果+1不存在
			if (iter_buff ==key_list.end()|| iter_buff->first!= iter->second->iter_value->first+1) {
				key_list.insert(iter_buff,make_pair(iter->second->iter_value->first + 1, list<string>({key})));
			} else {
				iter_buff->second.push_front(key);
			}		
			iter_buff = iter->second->iter_value;
			iter->second->iter_value++;
			iter->second->iter_key = iter->second->iter_value->second.begin();
			if (iter_buff->second.empty()) {
				key_list.erase(iter_buff);
			}
		}
		else {
			if (key_list.empty()||key_list.begin()->first != 1) {
				key_list.push_front(make_pair(1, list<string>({key})));
			}
			else {
				key_list.begin()->second.push_front(key);
			}
			Node* node = new Node(key_list.begin(), key_list.begin()->second.begin());
			key_node[key] = node;
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		auto iter = key_node.find(key);
		if (iter == key_node.end()) {
			return;
		}
		//删除此节点
		if (iter->second->iter_value->first == 1) {
			key_list.begin()->second.erase(iter->second->iter_key);
			if (key_list.begin()->second.empty()) {
				key_list.erase(key_list.begin());
			}
			key_node.erase(key);
		}
		else {
			iter->second->iter_value->second.erase(iter->second->iter_key);
			if (iter->second->iter_value == key_list.begin()) {
				key_list.push_front(make_pair(iter->second->iter_value->first - 1, list<string>({ key })));
				iter->second->iter_key = key_list.begin()->second.begin();
				iter->second->iter_value = key_list.begin();
			}
			else {
				auto iter_buff = iter->second->iter_value;
				iter_buff--;
				// 如果iter-1存在
				if (iter_buff->first == iter->second->iter_value->first - 1) {
					iter_buff->second.push_front(key);
				}
				else {
					key_list.insert(iter->second->iter_value, make_pair(iter->second->iter_value->first - 1, list<string>({ key })));
				}
				iter_buff = iter->second->iter_value;
				iter->second->iter_value--;
				iter->second->iter_key = iter->second->iter_value->second.begin();
				if (iter_buff->second.empty()) {
					key_list.erase(iter_buff);
				}
			}
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (key_node.empty()) {
			return "";
		}
		return *key_list.rbegin()->second.begin();
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (key_node.empty()) {
			return "";
		}
		return *key_list.begin()->second.begin();
	}
};

/**
* Your AllOne object will be instantiated and called as such:
* AllOne* obj = new AllOne();
* obj->inc(key);
* obj->dec(key);
* string param_3 = obj->getMaxKey();
* string param_4 = obj->getMinKey();
*/