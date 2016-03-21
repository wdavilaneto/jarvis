(function() {

	'use strict';

    /**
     * @ngdoc function
     * @name jarvisApp.controller:neuralNetController
     * @description
     * # neuralNetController
     * Controller of the jarvisApp
     */
    angular.module('jarvisApp')
        .controller('neuralNetEditController', neuralNetEditController);

        neuralNetEditController.$inject = ['$scope', '$state', '$stateParams', '$modal', '$location',
            'jsog', 'neuralNetService'];

        function neuralNetEditController($scope, $state, $stateParams , $modal, $location, jsog, neuralNetService  ) {

            var vm = this;

            // ***************************
            // Model Initializations
            // ***************************
            vm.master = 'neuralNet';
            vm.maxSelectBoxSize = 300;
            vm.original = {};
            vm.entity = neuralNetService.create();
            vm.searchSelects = neuralNetService.factorySearchSelect(); // Text Search Select utility Object
            vm.searchSelects.fromEntity(vm.entity);

            // ***************************************neuralNet
            // Controller Methods definitions
            // ***************************************
            vm.get = function( id ) {
                if (!id) {
                    id = $stateParams.id;                           // get id parameter from ui-router
                }
                console.log('retrieving rename.id = ' + id  );
                neuralNetService.get( {'id':id} , function (data) {
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
            vm.tabs.push({heading: "Principal", route: "neuralNetEdit.main", icon: "mdi-home", visible: "true"});

            vm.tabSelected = 'neuralNetEdit.main';

            // ******************************************************************************************
            // Master Details: Operations for Search and  editing of OneToMany/ManyToMany
            // ******************************************************************************************


            // Selects to Fullfill select boxes
            // Begin block

        }

})();
