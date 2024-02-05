function machine() {
    this.q = 'strike';
    this.w = 'snowball';
}
machine.prototype.name = 'kim';
var nunu = new machine();
var type_class = /** @class */ (function () {
    function type_class() {
        this.env = 'abc';
    }
    return type_class;
}());
var my_nunu = new type_class();
