/**
 *  Guick Generate class: https://github.com/wdavilaneto/guick
 *  Author: service-wdavilaneto@redhat.com
 *  This source is free under The Apache Software License, Version 2.0
 *  license url http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 * @ngdoc function
 * @name medicamentosApp.controller:cidadeController
 * @description
 * # cidadeController
 * Modal Controller for Cidade of the medicamentosApp
 */
(function() {

    'use strict';

    angular.module('medicamentosApp')
        .controller('ModalCidadeController', ModalCidadeController);

    ModalCidadeController.$inject = ['$scope', '$state', '$location', '$modalInstance', 'jsog', 'cidadeService', 'solicitacaoService', 'data'];

    function ModalCidadeController($scope, $state, $location, $modalInstance, jsog, cidadeService , solicitacaoService , data, readonly) {

        $scope.entity = data;  //.cidade;
        $scope.searchSelects = cidadeService.factorySearchSelect();
        $scope.searchSelects.fromEntity($scope.entity);

        if (!readonly) {
            // Selects to Fullfill select boxes
            // Begin block
        }
        // end block

        $scope.save = function () {
            console.log('Saving Modal');
            $scope.searchSelects.toEntity($scope.entity);
            cidadeService.save($scope.entity, function (successResult) {
                console.log(successResult);
                $scope.entity = {};
                $modalInstance.close($scope.entity);
            });
        };

        $scope.remove = function () {
            console.log('Deleting cidade with id:' + $scope.entity.id);
            cidadeService.remove({id: $scope.entity.id}, function (successResult) {
                console.log(successResult);
                $modalInstance.close($scope.entity);
                $state.go('cidadeEdit.main', {}, {reload: true});
            });
        };

        $scope.cancel = function () {
            $modalInstance.dismiss('cancel');
        };

    }

})();
