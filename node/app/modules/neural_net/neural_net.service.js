(function() {
	'use strict';

/**
 * @ngdoc service
 * @name jarvisApp.neuralNetService
 * @description
 * # myService
 * Factory in the jarvisApp.
 */
angular.module('jarvisApp').factory('neuralNetService', neuralNetService);

neuralNetService.$inject = ['$resource', 'gridService', 'ENV_CONFIG'];

function neuralNetService($resource, gridService, ENV_CONFIG) {
    var service = $resource('/neuralNet/api/neuralNet/:id', {}, {
        'findAll': { method: 'GET', url: '/neuralNet/api/neuralNet', isArray: false},
        'search': { method: 'POST', url: '/neuralNet/api/neuralNet/search', isArray: false},
        'searchText': { method: 'POST', url: '/neuralNet/api/neuralNet/searchText', isArray: false},
        'findAllOverdue':{ method: 'GET', url: '/neuralNet/api/neuralNet/overdue', isArray: false},
        'get': { method: 'GET'},
        'save': { method: 'POST'},
        'remove': { method: 'DELETE'}
    });

    var entity = {};

    service.getCurrentEntity = function (){
        return entity;
    };

    service.setCurrentEntity = function (obj){
        entity = obj;
    };

    service.create = function (){
        var e = {

        };
        return e;
    };

    service.factorySearchSelect = function (){
        // Factory SearchSelect Object for all "search text properties"
        var searchSelects = {

        };
        // utility method to copy selected object to entity ( reference
        searchSelects.toEntity = function (ref) {
            console.log(ref);

        };
        searchSelects.fromEntity = function (ref) {
            console.log(ref);
        };
        searchSelects.clear = function() {
        };
        return searchSelects;
    };

    service.createGridOptions = function (entitySelected, isEditMode){
        var options = gridService.createGridOptions(isEditMode);
        //options.rowTemplate= '<div ng-dblclick="detalhar(row.entity)" ng-style="{ \'cursor\': row.cursor }" ng-repeat="col in renderedColumns" ng-class="col.colIndex()" class="ngCell {{col.cellClass}}"><div class="ngVerticalBar" ng-style="{height: rowHeight}" ng-class="{ ngVerticalBarVisible: !$last }">&nbsp;</div><div ng-cell></div></div>';
        //options.rowTemplate= '<div ng-dblclick="editneuralNet(row.entity)" ng-style="{ \'cursor\': row.cursor }" ng-repeat="col in renderedColumns" ng-class="col.colIndex()" class="ngCell {{col.cellClass}}"><div class="ngVerticalBar" ng-style="{height: rowHeight}" ng-class="{ ngVerticalBarVisible: !$last }">&nbsp;</div><div ng-cell></div></div>';
        options.columnDefs = [];

        options.columnDefs.push({field: 'ufed', displayName: 'Ufed', sortable: false});
        options.columnDefs.push({field: 'nome', displayName: 'Nome', sortable: false});
        options.columnDefs.push({name:'btn_detail', displayName: '', enableColumnResizing: false, enableSorting: false, enableFiltering: false, cellTemplate: ENV_CONFIG.baseURL + 'modules/neuralNet/components/neural_net.grid.cell.detalhar.html', width : '35', resizable: false});
        if (isEditMode) {
            options.columnDefs.push({name:'btn_delete', displayName: '', enableColumnResizing: false, enableSorting: false, enableFiltering: false,  cellTemplate: ENV_CONFIG.baseURL + 'modules/neuralNet/components/neural_net.grid.cell.delete.html' , width : '35', resizable: false});
        }
        return options;
    };
    return service;
}

})();
