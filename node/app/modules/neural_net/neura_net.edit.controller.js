(function() {

	'use strict';

    /**
     * @ngdoc function
     * @name medicamentosApp.controller:cidadeController
     * @description
     * # cidadeController
     * Controller of the medicamentosApp
     */
    angular.module('medicamentosApp')
        .controller('cidadeEditController', cidadeEditController);

        cidadeEditController.$inject = ['$scope', '$state', '$stateParams', '$modal', '$location',
            'jsog', 'cidadeService', 'solicitacaoService'];

        function cidadeEditController($scope, $state, $stateParams , $modal, $location, jsog, cidadeService , solicitacaoService ) {

            var vm = this;

            // ***************************
            // Model Initializations
            // ***************************
            vm.master = 'cidade';
            vm.maxSelectBoxSize = 300;
            vm.original = {};
            vm.entity = cidadeService.create();
            vm.searchSelects = cidadeService.factorySearchSelect(); // Text Search Select utility Object
            vm.searchSelects.fromEntity(vm.entity);

            // ***************************************cidade
            // Controller Methods definitions
            // ***************************************
            vm.get = function( id ) {
                if (!id) {
                    id = $stateParams.id;                           // get id parameter from ui-router
                }
                console.log('retrieving rename.id = ' + id  );
                cidadeService.get( {'id':id} , function (data) {
                    vm.entity = data;                           // set managed entity from service
                    vm.original = angular.copy(vm.entity);                // backup original values;
                    vm.searchSelects.fromEntity($scope.entity); // update search selects values;
                }, function (error){
                    console.log(error);                             // TODO:
                });
            };

            vm.clearForm = function () {
                vm.entity = angular.copy(vm.original);
            };

            // ************************************
            // watches
            // ************************************
            vm.changeTab = function (tab) {
                $state.go(tab);
                vm.tabSelected = tab;
            }

            // ****************************************
            // Controller init (on load) service calls
            // ****************************************
            vm.tabs = [];
            vm.tabs.push({heading: "Principal", route: "cidadeEdit.main", icon: "mdi-home", visible: "true"});

            vm.tabSelected = 'cidadeEdit.main';

            // ******************************************************************************************
            // Master Details: Operations for Search and  editing of OneToMany/ManyToMany
            // ******************************************************************************************


            // Selects to Fullfill select boxes
            // Begin block

        }

})();
