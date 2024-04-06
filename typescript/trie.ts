class Queue {
    public size;
    public queue;
    public front;
    public rear;
    constructor() {
        this.queue = []
        this.front = 0
        this.rear = 0
        this.size = 0
    }
    
    enqueue(value) {
        this.queue[this.rear++] = value
        this.size++
    }
    
    dequeue() {
        const value = this.queue[this.front]
        delete this.queue[this.front++]
        this.size--
        return value
    }
    
    isEmpty() {
        return this.front === this.rear
    }
}

class RootNode {
    public value;
    public children;
    public isWordExists;

    constructor(value = "") {
        this.value = value
        this.children = new Map()
        this.isWordExists = false
    }
}

class Trie {
    public root;
    constructor() {
        this.root = new RootNode()
    }

    insert(string) {
        let currentNode = this.root

        for (const char of string) {
        if (!currentNode.children.has(char)) {
            currentNode.children.set(
            char,
            new RootNode(currentNode.value + char)
            )
        }

        currentNode = currentNode.children.get(char)
        }

        currentNode.isWordExists = true
    }

    find(string) {
        let currentNode = this.root

        for (const char of string) {
            if (!currentNode.children.has(char)) {
                return undefined
            }
            currentNode = currentNode.children.get(char)
        }

        return currentNode
    }

    has(string) {
        return this.find(string) ? true : false
    }

    autoComplete(prefix) {
        const prefixNode = this.find(prefix)
        if(!prefixNode || !prefixNode.children.size) {
            return "해당되는 단어가 없습니다."
        }

        const words :string[]  = []
        const queue = new Queue()
        queue.enqueue(prefixNode)

        while(queue.size) {
            const currentNode = queue.dequeue()
            if (currentNode.isWordExists) {
                words.push(currentNode.value)
            }

            for(const child of currentNode.children.values()) {
                queue.enqueue(child)
            }
        }
        return words
    }
}


const trie = new Trie()
trie.insert("hero");
trie.insert("haha");
trie.insert("hello");
var test = trie.autoComplete("he");
console.log(trie.root);