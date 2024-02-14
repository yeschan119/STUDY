var env = 'IMS-Prod';
var test9 = env != null && env != undefined && typeof env == 'string' ? env : env + '00';
console.log(test9);
function test_func9(env) {
    console.log(env);
    try {
        if (env.includes('IMS') | env.includes('Prod')) {
            console.log('IMS');
        }
        else {
            console.log('here');
            throw new Error('ERROR BBB');
        }
    }
    catch (error) {
        throw new Error(error.message);
    }
}
test_func9(env);
