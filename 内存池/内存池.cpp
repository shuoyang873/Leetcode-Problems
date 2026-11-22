#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


static inline size_t align_up(size_t n, size_t align) {
	return (n + (align - 1)) & ~(align - 1);
}

class FixedSizePool {
public:
	FixedSizePool(size_t block_size, size_t blocks_per_page=1024) { 
		block_size_ = adjust_align_up(block_size);
		blocks_per_page_ = blocks_per_page;
		free_list = NULL;
	}
	~FixedSizePool(){
		for (void* p : pages) {
			::operator delete[](p);
		}
	}
	size_t block_per_page() { return blocks_per_page_; }
	size_t block_size() { return block_size_; }
	void*allocate(){
		if (!free_list) {
			expand();
		}
		Node* node = free_list;
		free_list = node->next;
		return node;
	}
	void deallocate(void* p){
		Node* node = static_cast<Node*>(p);
		node->next = free_list;
		free_list = node;
	}
private:
	void expand() {
		size_t page_bytes = block_size_ * blocks_per_page_;
		char* page = static_cast<char*>(::operator new[](page_bytes));
		pages.push_back(page);

		for (size_t i = 0; i < blocks_per_page_; i++) {
			char* addr = page + i * block_size_;
			Node* n = reinterpret_cast<Node*>(addr);
			n->next = free_list;
			free_list = n;
		}
	}
	size_t adjust_align_up(size_t block_size) {
		size_t min_n = sizeof(void*);
		size_t a = min(min_n, alignof(block_size));
		return a;
	}
	struct Node { Node* next; };
	Node* free_list;
	size_t block_size_;
	size_t blocks_per_page_;
	vector<void*>pages;
};


struct Particle {
	float x, y, z;
	int life;
	static void* operator new(size_t n);
	static void operator delete(void* p)noexcept;
	void update() { ++life; }
};

static FixedSizePool g_garticle_pool(sizeof(Particle), 4096);
void* Particle:: operator new(size_t n) {
	return g_garticle_pool.allocate();
}

void Particle::operator delete(void* p) {
	g_garticle_pool.deallocate(p);
}