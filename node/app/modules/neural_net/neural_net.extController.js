(function() {
	'use strict';

/**
 *  Guick Generate class: https://github.com/wdavilaneto/guick
 *  Author: service-wdavilaneto@redhat.com
 *  This source is free under The Apache Software License, Version 2.0
 *  license url http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 * @ngdoc function
 * @name jarvisApp.controller:neuralNetExtController
 * @description
 * # neuralNetExtController
 * Extended Controller pr Master Detail and other specific operations of the jarvisApp
 */
    angular.module('jarvisApp')
        .controller('neuralNetExtController', neuralNetExtController);

    neuralNetExtController.$inject = ['$scope', '$stateParams', '$modal', '$location', 'jsog', 'neuralNetService' ];

    function neuralNetExtController($scope, $stateParams , $modal, $location, jsog, neuralNetService ) {

        $scope.masterDetail = null;

        $scope.create = function ( parent ) {
            $scope.selected = null;
            $scope.selected = {
                neuralNet:parent
            };
        };

        // ******************************************************************************************
        // Master Details: Operations for Search and  editing of OneToMany/ManyToMany
        // ******************************************************************************************

        $scope.back = function (){
            if ($stateParams.child) {
                console.log('Redirecting to /neuralNet/'+ $stateParams.id + '/' + $stateParams.child);
                $location.path('/neuralNet/'+ $stateParams.id + '/' + $stateParams.child);
            } else {
                $window.history.back();
            }
        };

        $scope.clear = function () {
            $scope.selected = null;
        };

    }

})();
