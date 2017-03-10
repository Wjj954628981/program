'use strict';
function count(state, action) {
    var defaultState = {
        year: 2015
    }
    state = state||defaultState;
    switch (action.type){
        case 'add':
            return {
                year:state.year+1
            };
        case 'sub':
            return{
                year:state.year-1
            };
        default:
            return state;
    }
    var createStore = require('redux').createStore;
    var store = createStore(count());

    store.subscribe(function () {
        console.log('this year is :',store.getState().year);
    });

    var action1 = {type:'add'};
    var action2 = {type:'add'};
    var action3 = {type:'sub'};

    store.dispatch(action1);
    store.dispatch(action2);
    store.dispatch(action3);

}