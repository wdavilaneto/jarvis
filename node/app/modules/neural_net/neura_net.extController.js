(function() {
	'use strict';

/**
 *  Guick Generate class: https://github.com/wdavilaneto/guick
 *  Author: service-wdavilaneto@redhat.com
 *  This source is free under The Apache Software License, Version 2.0
 *  license url http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 * @ngdoc function
 * @name medicamentosApp.controller:cidadeExtController
 * @description
 * # cidadeExtController
 * Extended Controller pr Master Detail and other specific operations of the medicamentosApp
 */
    angular.module('medicamentosApp')
        .controller('cidadeExtController', cidadeExtController);

    cidadeExtController.$inject = ['$scope', '$stateParams', '$modal', '$location', 'jsog', 'cidadeService' , 'solicitacaoService'];

    function cidadeExtController($scope, $stateParams , $modal, $location, jsog, cidadeService , solicitacaoService) {

        $scope.masterDetail = null;

        $scope.create = function ( parent ) {
            $scope.selected = null;
            $scope.selected = {
                cidade:parent
            };
        };

        // ******************************************************************************************
        // Master Details: Operations for Search and  editing of OneToMany/ManyToMany
        // ******************************************************************************************

        $scope.back = function (){
            if ($stateParams.child) {
                console.log('Redirecting to /Cidade/'+ $stateParams.id + '/' + $stateParams.child);
                $location.path('/cidade/'+ $stateParams.id + '/' + $stateParams.child);
            } else {
                $window.history.back();
            }
        };

        $scope.clear = function () {
            $scope.selected = null;
        };

    }

})();
