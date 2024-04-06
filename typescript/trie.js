var Queue = /** @class */ (function () {
    function Queue() {
        this.queue = [];
        this.front = 0;
        this.rear = 0;
        this.size = 0;
    }
    Queue.prototype.enqueue = function (value) {
        this.queue[this.rear++] = value;
        this.size++;
    };
    Queue.prototype.dequeue = function () {
        var value = this.queue[this.front];
        delete this.queue[this.front++];
        this.size--;
        return value;
    };
    Queue.prototype.isEmpty = function () {
        return this.front === this.rear;
    };
    return Queue;
}());
var RootNode = /** @class */ (function () {
    function RootNode(value) {
        if (value === void 0) { value = ""; }
        this.value = value;
        this.children = new Map();
        this.isWordExists = false;
    }
    return RootNode;
}());
var Trie = /** @class */ (function () {
    function Trie() {
        this.root = new RootNode();
    }
    Trie.prototype.insert = function (string) {
        var currentNode = this.root;
        for (var _i = 0, string_1 = string; _i < string_1.length; _i++) {
            var char = string_1[_i];
            if (!currentNode.children.has(char)) {
                currentNode.children.set(char, new RootNode(currentNode.value + char));
            }
            currentNode = currentNode.children.get(char);
        }
        currentNode.isWordExists = true;
    };
    Trie.prototype.find = function (string) {
        var currentNode = this.root;
        for (var _i = 0, string_2 = string; _i < string_2.length; _i++) {
            var char = string_2[_i];
            if (!currentNode.children.has(char)) {
                return undefined;
            }
            currentNode = currentNode.children.get(char);
        }
        return currentNode;
    };
    Trie.prototype.has = function (string) {
        return this.find(string) ? true : false;
    };
    Trie.prototype.autoComplete = function (prefix) {
        var prefixNode = this.find(prefix);
        if (!prefixNode || !prefixNode.children.size) {
            return "해당되는 단어가 없습니다.";
        }
        var words = [];
        var queue = new Queue();
        queue.enqueue(prefixNode);
        while (queue.size) {
            var currentNode = queue.dequeue();
            if (currentNode.isWordExists) {
                words.push(currentNode.value);
            }
            for (var _i = 0, _a = currentNode.children.values(); _i < _a.length; _i++) {
                var child = _a[_i];
                queue.enqueue(child);
            }
        }
        return words;
    };
    return Trie;
}());
var trie = new Trie();
trie.insert("hero");
trie.insert("haha");
trie.insert("hello");
var test = trie.autoComplete("he");
console.log(trie.root);
