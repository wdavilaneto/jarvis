/**
 *  Guick Generate class: https://github.com/wdavilaneto/guick
 *  Author: service-wdavilaneto@redhat.com
 *  This source is free under The Apache Software License, Version 2.0
 *  license url http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 * @ngdoc function
 * @name jarvisApp.controller:neuralNetController
 * @description
 * # neuralNetController
 * Modal Controller for neuralNet of the jarvisApp
 */
(function() {

	'use strict';

    angular.module('jarvisApp')
        .controller('ModalneuralNetController', ModalneuralNetController);

    ModalneuralNetController.$inject = ['$scope', '$state', '$location', '$modalInstance', 'jsog', 'neuralNetService'];

    function ModalneuralNetController($scope, $state, $location, $modalInstance, jsog, neuralNetService  , data, readonly) {

        $scope.searchSelects = neuralNetService.factorySearchSelect();
        $scope.searchSelects.fromEntity($scope.entity);

        if (!readonly) {
            // Selects to Fullfill select boxes
            // Begin block
                                                }
        // end block

            $scope.save = function () {
            console.log('Saving Modal');
                $scope.searchSelects.toEntity($scope.entity);
                neuralNetService.save($scope.entity, function (successResult) {
                console.log(successResult);
                    $scope.entity = {};
                    $modalInstance.close($scope.entity);
            });
        };

        $scope.remove = function () {
            console.log('Deleting neuralNet with id:' + $scope.entity.id);
                neuralNetService.remove({id: $scope.entity.id}, function (successResult) {
                console.log(successResult);
                    $modalInstance.close($scope.entity);
                    $state.go('neuralNetEdit.main', {}, {reload: true});
            });
        };

            $scope.cancel = function () {
                $modalInstance.dismiss('cancel');
        };

    }

})();
