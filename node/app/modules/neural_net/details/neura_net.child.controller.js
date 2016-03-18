
(function() {
	'use strict';

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
     * Controller of the medicamentosApp
     */
    angular.module('medicamentosApp').controller('cidadeChildController', cidadeChildController);

    cidadeChildController.$inject = ['$scope', '$stateParams', '$modal', '$location', 'jsog', 'cidadeService' , 'solicitacaoService'];

    function cidadeChildController($scope, $stateParams , $modal, $location, jsog, cidadeService , solicitacaoService ) {

        var vm = this;

        $scope.gridOptions = cidadeService.createGridOptions( true );
        $scope.pagination = $scope.gridOptions.getPagination(); // just for ease use/access
        $scope.resultPage = {}; // Paged result for search filter

        $scope.findCidade();
    }

})();
